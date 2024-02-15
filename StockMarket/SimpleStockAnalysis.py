import sys
import yfinance as yf
import matplotlib.pyplot as plt
from matplotlib.backends.backend_qt5agg import FigureCanvas
from matplotlib.backends.backend_qt5 import FigureManager
from PyQt5 import QtWidgets, uic

class StockDataViewer(QtWidgets.QMainWindow):
    def __init__(self):
        super(StockDataViewer, self).__init__()
        uic.loadUi("stock_data_viewer.ui", self)

        self.button.clicked.connect(self.fetch_and_plot_data)
        self.chart_type_radiobutton1.toggled.connect(self.update_chart_type)
        self.chart_type_radiobutton2.toggled.connect(self.update_chart_type)

    def fetch_and_plot_data(self):
        stock_name = self.entry.text() + '.NS'

        try:
            # Fetch historical stock data
            ticker = yf.Ticker(stock_name)
            historical_data = ticker.history(period='max')

            # Plotting the stock data
            fig, ax = plt.subplots(figsize=(10, 6))
            ax.set_title(stock_name + ' Stock Price')

            # Check if candlestick chart is selected
            if self.chart_type_radiobutton2.isChecked():
                mpf.plot(historical_data, type='candle', ax=ax, volume=True, show_nontrading=True)
            else:
                ax.plot(historical_data.index, historical_data['Close'], label='Close Price')
                ax.set_xlabel('Date')
                ax.set_ylabel('Price')
                ax.legend()

            # Enable zooming in and out
            if self.zoom_checkbox.isChecked():
                ax.axis('zoomed')

            

            # Create the canvas
            canvas = FigureCanvas(fig)
            self.canvas_layout.addWidget(canvas)

            # Create the figure manager
            figure_manager = FigureManager(canvas, 1)
            figure_manager.canvas.figure = fig
            fig.set_canvas(figure_manager.canvas)

        except Exception as e:
            self.statusbar.showMessage("Error fetching data for " + stock_name)

    def update_chart_type(self):
        chart_selected = "Candlestick" if self.chart_type_radiobutton2.isChecked() else "Line"
        self.zoom_checkbox.setChecked(False)
        self.zoom_checkbox.setEnabled(chart_selected != "Candlestick")

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = StockDataViewer()
    window.show()
    sys.exit(app.exec_())
