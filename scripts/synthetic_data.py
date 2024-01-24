'''

    Synthetic dataset generator script
    run with 
        python3 synthetic_data.py --num_entries <NE> --num_features <NF>  --filename <FN>

    the dataset will be saved to ../data/<FN>
    
'''

import pandas as pd
import random
import argparse

def generate_synthetic_dataset(entries, features):
    # Create a dictionary to store data for each feature
    data = {f"Feature_{i+1}": [random.randrange(100) for _ in range(entries)] for i in range(features)}
    
    # Create a DataFrame 
    df = pd.DataFrame(data)
    
    return df

def save_to_csv(df, filename):
    df.to_csv(filename, index=False, header=False) # header=True to include feautures names 
    print(f"Dataset saved to {filename}")

def main():

    # Parse CLI args
    parser = argparse.ArgumentParser(description="Synthetic dataset generator script")
    parser.add_argument("--num_entries", type=int, default=10, help="Number of entries in the dataset")
    parser.add_argument("--num_features", type=int, default=5, help="Number of features in the dataset")
    parser.add_argument("--filename", type=str, default='UnDefined.csv', help="Filename to save the dataset to")
    args = parser.parse_args()

    entries = args.num_entries
    features = args.num_features
    filename = args.filename

    synthetic_dataset = generate_synthetic_dataset(entries, features)

    save_to_csv(synthetic_dataset, '../data/'+filename)

if __name__ == "__main__":
    main()
