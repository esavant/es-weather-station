import pandas as pd
import numpy as np

# Load the Excel file
excel_path = "winddata2.xlsx"
df = pd.read_excel(excel_path, sheet_name='Sheet1')

# Convert Vernier time from min to milliseconds
df['Time Vernier (ms)'] = df['Time (min)'] * 60 * 1000

# Drop rows with NaNs
vernier_time_ms = df['Time Vernier (ms)'].dropna()
revp_time_ms = df['Time (ms)'].dropna()
revpspeed = df['Speed (mph)'].dropna()

# Interpolate DHT22 humidity at Vernier timestamps
interpolated_speed = np.interp(
    vernier_time_ms, revp_time_ms, revpspeed
)

# Create aligned DataFrame
aligned_df = pd.DataFrame({
    'Time (min)': df['Time (min)'],
    'Vernier Speed (mph)': df['Vernier Speed (mph)'],
    'Interpolated Wind Speed': interpolated_speed
})

# Export to Excel
output_path = "aligned_wind_data.xlsx"
aligned_df.to_excel(output_path, index=False)

print(f"Interpolated file saved to: {output_path}")
