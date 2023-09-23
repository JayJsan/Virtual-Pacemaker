#!/usr/bin/env python3

import pandas
import sys
from io import TextIOBase
import matplotlib.pyplot as plt
import numpy as np

def read_c_vals(file: TextIOBase):
    output = {}
    for line in file.readlines():
        parts = line.split(' ')
        name_part = next((part for part in parts if 'VALUE' in part), None)
        if name_part is None:
            continue

        # grab the first rightmost item that is an integer
        int_part = next((part for part in reversed(parts) if part.strip().isnumeric()), None)
        if int_part is None:
            continue

        name = name_part.strip().rstrip('_VALUE')
        output[name] = int(int_part.strip())
    
    return output

with open('./timing.h') as file:
    CONSTS = read_c_vals(file)
            
print(pandas.DataFrame(CONSTS.values(), index=CONSTS.keys()), flush=True)

if len(sys.argv) < 2:
    print("Please pass a file path as a parameter")
    exit(-1)


data = pandas.read_csv(sys.argv[1], header=0)
data = data.rename(columns=lambda x: x.strip()).copy()

data['AVI'] = np.zeros_like(data['A'], dtype=np.float64)
data['PVARP'] = np.zeros_like(data['A'], dtype=np.float64)
data['VRP'] = np.zeros_like(data['A'], dtype=np.float64)
data['AEI'] = np.zeros_like(data['A'], dtype=np.float64)
data['LRI'] = np.zeros_like(data['A'], dtype=np.float64)
data['URI'] = np.zeros_like(data['A'], dtype=np.float64)


for i, (a, v) in enumerate(zip(data['A'], data['V'])):
    

    if a != 0 and not data['PVARP'][i]:
        colIndex = data.columns.get_loc('AVI')
        data.iloc[i:i+CONSTS['AVI']-1, colIndex] = 0.1


    if v != 0 and not data['VRP'][i]:
        colIndex = data.columns.get_loc('AEI')
        data.iloc[i:i+CONSTS['AEI']-1, colIndex] = 0.4

        colIndex = data.columns.get_loc('LRI')
        data.iloc[i:i+CONSTS['LRI']-1, colIndex] = 0.5

        colIndex = data.columns.get_loc('URI')
        data.iloc[i:i+CONSTS['URI']-1, colIndex] = 0.6

    if v != 0:
        colIndex = data.columns.get_loc('PVARP')
        data.iloc[i:i+CONSTS['PVARP']-1, colIndex] = 0.2

        colIndex = data.columns.get_loc('VRP')
        data.iloc[i:i+CONSTS['VRP']-1, colIndex] = 0.3

    i += 1



data['Time'] = data['Time'] + 2000
plot = data.plot(x='Time', y=['A', 'V', 'AVI', 'PVARP', 'VRP', 'AEI', 'LRI', 'URI'], title=sys.argv[1])

plt.show(block=True)