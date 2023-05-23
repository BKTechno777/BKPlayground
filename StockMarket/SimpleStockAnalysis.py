import tkinter as tk
import yfinance as yf
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

def fetch_and_plot_data():
    stock_name = entry.get()

    try:
        # Fetch real-time stock data
        ticker = yf.Ticker(stock_name)
        real_time_data = ticker.history(period='1d')

        # Fetch historical stock data
        historical_data = ticker.history(period='max')

        # Print real-time stock data
        print("Real-time Stock Data:")
        print(real_time_data)

        # Print historical stock data
        print("Historical Stock Data:")
        print(historical_data.head())

        # Plotting the stock data
        plt.figure(figsize=(10, 6))
        plt.plot(real_time_data.index, real_time_data['Close'], label='Real-time Close Price')
        plt.plot(historical_data.index, historical_data['Close'], label='Historical Close Price')
        plt.title(stock_name + ' Stock Price')
        plt.xlabel('Date')
        plt.ylabel('Price')
        plt.legend()

        # Embed the plot in the GUI
        canvas = FigureCanvasTkAgg(plt.gcf(), master=window)
        canvas.draw()
        canvas.get_tk_widget().pack()

    except Exception as e:
        label.config(text="Error fetching data for " + stock_name)

# Create the main window
window = tk.Tk()
window.title("Stock Data Viewer")

# Create the label and entry
label = tk.Label(window, text="Enter Stock Name:")
label.pack()
entry = tk.Entry(window)
entry.pack()

# Create the fetch and plot button
button = tk.Button(window, text="Fetch and Plot Data", command=fetch_and_plot_data)
button.pack()

# Start the GUI event loop
window.mainloop()
