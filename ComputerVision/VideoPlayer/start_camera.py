# -*- coding: utf-8 -*-
"""
Created on Mon May 15 23:54:43 2023

@author: USER
"""

from PyQt5.QtWidgets import QDialog, QVBoxLayout, QHBoxLayout, QLabel, QLineEdit, QPushButton


class StartCameraDialog(QDialog):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Start Camera")

        # Create the camera index label and edit
        self.camera_index_label = QLabel("Camera Index:")
        self.camera_index_edit = QLineEdit()
        self.camera_index_edit.setText("0")

        # Create the OK and Cancel buttons
        self.ok_button = QPushButton("OK")
        self.ok_button.clicked.connect(self.accept)
        self.cancel_button = QPushButton("Cancel")
        self.cancel_button.clicked.connect(self.reject)

        # Create the layout and add the widgets
        self.layout = QVBoxLayout()
        self.setLayout(self.layout)
        self.horizontal_layout = QHBoxLayout()
        self.horizontal_layout.addWidget(self.camera_index_label)
        self.horizontal_layout.addWidget(self.camera_index_edit)
        self.layout.addLayout(self.horizontal_layout)
        self.button_layout = QHBoxLayout()
        self.button_layout.addWidget(self.ok_button)
        self.button_layout.addWidget(self.cancel_button)
        self.layout.addLayout(self.button_layout)

    @property
    def camera_index(self):
        return int(self.camera_index_edit.text())
