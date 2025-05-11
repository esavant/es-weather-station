import pandas as pd
import numpy as np

# Load the Excel file
excel_path = "humidity-test-results2.xlsx"
df = pd.read_excel(excel_path, sheet_name='Sheet1')

# Convert Vernier time from hours to milliseconds
df['Time Vernier (ms)'] = df['Time (hr)'] * 3600 * 1000

# Drop rows with NaNs
vernier_time_ms = df['Time Vernier (ms)'].dropna()
dht_time_ms = df['Time(ms)'].dropna()
dht_humidity = df['Humidity(%)'].dropna()

# Interpolate DHT22 humidity at Vernier timestamps
interpolated_dht_humidity = np.interp(
    vernier_time_ms, dht_time_ms, dht_humidity
)

# Create aligned DataFrame
aligned_df = pd.DataFrame({
    'Time (hr)': df['Time (hr)'],
    'Vernier Humidity (RH %)': df['Vernier Humidity (RH %)'],
    'Interpolated DHT22 Humidity (RH %)': interpolated_dht_humidity
})

# Export to Excel
output_path = "aligned_humidity_data.xlsx"
aligned_df.to_excel(output_path, index=False)

print(f"Interpolated file saved to: {output_path}")

