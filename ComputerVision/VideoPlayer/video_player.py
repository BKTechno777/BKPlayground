# -*- coding: utf-8 -*-
"""
Created on Mon May 15 23:53:05 2023

@author: USER
"""

import sys
import cv2
from PyQt5.QtCore import Qt, QTimer
from PyQt5.QtGui import QImage, QPixmap
from PyQt5.QtWidgets import QApplication, QMainWindow, QWidget, QLabel, QVBoxLayout, QHBoxLayout, QPushButton
from load_file import LoadFileDialog
from start_camera import StartCameraDialog


class VideoPlayer(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Video Player")
        self.setGeometry(100, 100, 640, 480)

        # Create the main widget and layout
        self.main_widget = QWidget()
        self.main_layout = QVBoxLayout()
        self.main_widget.setLayout(self.main_layout)
        self.setCentralWidget(self.main_widget)

        # Create the video label and layout
        self.video_label = QLabel()
        self.video_layout = QHBoxLayout()
        self.video_layout.addWidget(self.video_label)
        self.main_layout.addLayout(self.video_layout)

        # Create the button layout
        self.button_layout = QHBoxLayout()
        self.main_layout.addLayout(self.button_layout)

        # Create the load file button
        self.load_file_button = QPushButton("Load File")
        self.load_file_button.clicked.connect(self.load_file)
        self.button_layout.addWidget(self.load_file_button)

        # Create the start camera button
        self.start_camera_button = QPushButton("Start Camera")
        self.start_camera_button.clicked.connect(self.start_camera)
        self.button_layout.addWidget(self.start_camera_button)

        # Create the play/pause button
        self.play_button = QPushButton("Play")
        self.play_button.clicked.connect(self.play_pause)
        self.play_button.setEnabled(False)
        self.button_layout.addWidget(self.play_button)

        # Create the stop button
        self.stop_button = QPushButton("Stop")
        self.stop_button.clicked.connect(self.stop)
        self.stop_button.setEnabled(False)
        self.button_layout.addWidget(self.stop_button)

        # Create the video capture object
        self.video_capture = None

        # Create the timer object
        self.timer = QTimer()
        self.timer.timeout.connect(self.update_frame)

    def load_file(self):
        load_file_dialog = LoadFileDialog()
        if load_file_dialog.exec_():
            file_path = load_file_dialog.file_path
            self.video_capture = cv2.VideoCapture(file_path)
            self.start_timer()

            # Disable the start camera button and enable the stop button
            self.start_camera_button.setEnabled(False)
            self.stop_button.setEnabled(True)

    def start_camera(self):
        start_camera_dialog = StartCameraDialog()
        if start_camera_dialog.exec_():
            camera_index = start_camera_dialog.camera_index
            self.video_capture = cv2.VideoCapture(camera_index)
            self.start_timer()

            # Disable the load file button and enable the stop button
            self.load_file_button.setEnabled(False)
            self.stop_button.setEnabled(True)

    def start_timer(self):
        if not self.timer.isActive():
            self.timer.start(30)  # Set the timer to 30 FPS

        # Enable the play/pause button
        self.play_button.setEnabled(True)

    def play_pause(self):
        if self.timer.isActive():
            self.timer.stop()
            self.play_button.setText("Play")
        else:
            self.timer.start()
            self.play_button.setText("Pause")

    def stop(self):
        self.video_capture.release()
        self.timer.stop()

        # Disable the play/pause and stop buttons and enable the load file and start camera buttons
        self.play_button.setEnabled(False)
        self.stop_button.setEnabled(False)
        self.load_file_button.setEnabled(True)
        self.start_camera_button.setEnabled(True)

    def update_frame(self):
        ret, frame = self.video_capture.read()
        if ret:
            # Convert the frame to QImage and display it on the label
            rgb_image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            h, w, ch = rgb_image.shape
            bytes_per_line = ch * w
            q_image = QImage(rgb_image.data, w, h, bytes_per_line, QImage.Format_RGB888)
            self.video_label.setPixmap(QPixmap.fromImage(q_image))
        else:
            self.stop()

if __name__ == "__main__":
    app = QApplication(sys.argv)
    video_player = VideoPlayer()
    video_player.show()
    sys.exit(app.exec_())
