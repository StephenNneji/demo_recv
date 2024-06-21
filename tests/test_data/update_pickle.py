import os
import numpy as np
import pickle


TEST_DIR_PATH = ''


data_path = os.path.join(TEST_DIR_PATH, 'plotting_data.pickle')    
with open(data_path, 'rb') as f:
    with open("newvariables.pkl", "wb") as output:
        loaded_data = pickle.load(f)
        print(type(loaded_data['reflectivity']))
        loaded_data['reflectivity'] =[loaded_data['reflectivity'][0][0], loaded_data['reflectivity'][1][0], loaded_data['reflectivity'][2][0]]
        loaded_data['shiftedData'] = [loaded_data['shiftedData'][0][0], loaded_data['shiftedData'][1][0], loaded_data['shiftedData'][2][0]]
        

        pickle.dump(loaded_data, output, 2)
