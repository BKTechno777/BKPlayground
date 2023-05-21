# -*- coding: utf-8 -*-
"""
Created on Mon May 15 23:53:43 2023

@author: USER
"""

from PyQt5.QtWidgets import QFileDialog


class LoadFileDialog:
    def __init__(self):
        self.file_path = None
        options = QFileDialog.Options()
        options |= QFileDialog.DontUseNativeDialog
        file_filter = "Video files (*.mp4 *.avi *.mkv);;All files (*)"
        dialog = QFileDialog()
        dialog.setOptions(options)
        dialog.setNameFilter(file_filter)
        dialog.setLabelText(QFileDialog.Accept, "Load")
        if dialog.exec_() == QFileDialog.Accepted:
            self.file_path = dialog.selectedFiles()[0]
