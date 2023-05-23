import tkinter as tk
import yfinance as yf
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import mplfinance as mpf


class GUIActions:
    def __init__(self, window):
        self.window = window

        self.label = tk.Label(self.window, text="Enter Stock Name:")
        self.label.pack()
        self.entry = tk.Entry(self.window)
        self.entry.pack()

        self.button = tk.Button(self.window, text="Fetch and Plot Data", command=self.fetch_and_plot_data)
        self.button.pack()

        self.chart_type_label = tk.Label(self.window, text="Select Chart Type:")
        self.chart_type_label.pack()
        self.chart_type = tk.StringVar(value='Line')
        self.chart_type_radiobutton1 = tk.Radiobutton(self.window, text="Line", variable=self.chart_type, value='Line', command=self.update_chart_type)
        self.chart_type_radiobutton1.pack()
        self.chart_type_radiobutton2 = tk.Radiobutton(self.window, text="Candlestick", variable=self.chart_type, value='Candlestick', command=self.update_chart_type)
        self.chart_type_radiobutton2.pack()

        self.zoom_enabled = tk.BooleanVar(value=False)
        self.zoom_checkbox = tk.Checkbutton(self.window, text="Enable Zoom", variable=self.zoom_enabled)
        self.zoom_checkbox.pack()

    def fetch_and_plot_data(self):
        stock_name = self.entry.get() + '.NS'
        stock_actions = StockActions()

        try:
            historical_data = stock_actions.fetch_historical_data(stock_name)

            if historical_data is not None:
                stock_actions.plot_stock_data(stock_name, historical_data, self.chart_type.get(), self.zoom_enabled.get())
                plt.show()

        except Exception as e:
            self.label.config(text="Error fetching data for " + stock_name)

    def update_chart_type(self):
        chart_selected = self.chart_type.get()
        if chart_selected == 'Candlestick':
            self.zoom_checkbox.deselect()
            self.zoom_checkbox.config(state='disabled')
        else:
            self.zoom_checkbox.config(state='normal')


class StockActions:
    def fetch_historical_data(self, stock_name):
        ticker = yf.Ticker(stock_name)
        historical_data = ticker.history(period='max')
        return historical_data

    def plot_stock_data(self, stock_name, historical_data, chart_type, zoom_enabled):
        fig, ax = plt.subplots(figsize=(10, 6))
        ax.set_title(stock_name + ' Stock Price')

        if chart_type == 'Candlestick':
            mpf.plot(historical_data, type='candle', ax=ax, volume=True, show_nontrading=True)
        else:
            ax.plot(historical_data.index, historical_data['Close'], label='Close Price')
            ax.set_xlabel('Date')
            ax.set_ylabel('Price')
            ax.legend()

        if zoom_enabled:
            ax.axis('zoomed')


if __name__ == "__main__":
    window = tk.Tk()
    window.title("Stock Data Viewer")
    window.geometry("800x600")

    gui_actions = GUIActions(window)

    window.mainloop()
