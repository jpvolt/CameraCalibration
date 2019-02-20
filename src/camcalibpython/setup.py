import setuptools

with open("README.md", "r") as fh:
    long_description = fh.read()

setuptools.setup(
    name="CamCalib-jpvolt",
    version="0.1.0",
    author="João Pedro VOLTani",
    author_email="jpvoltdeveloper@gmail.com",
    description="Opencv based camera calibration lib for stereo vision",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/jpvolt/CameraCalibration",
    packages=setuptools.find_packages(),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
)
