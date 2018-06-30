# ImageBrowser
This is a seed OSX application that illustrates Objective-C to C++ bridging  and follows on a Domain Driven Design application structure forked from an example from Apple. It supports drag-drop for scalable display with an extension to parse DICOM files based on reused open source code.


# Reference:

This project embeds library code from this open source project to accomplish the DICOM Part 10 Media File Set reads:
https://github.com/sprinfall/dcmlite

NOTE: It appears this C++ code does have some issues with certain DICOM file streams, potentially around Private Elements as witnessed with some Ultrasound single and multi-frame images. Still investigating.
