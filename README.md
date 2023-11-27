# <div align="center">Hey 👋, I'm The-R4V3N!</div>  

----

## <div align="center"> Connect with me  

<div align="center">
 <a href="https://github.com/The-R4V3N" target="_blank">
<img src=https://img.shields.io/badge/github-%2324292e.svg?&style=for-the-badge&logo=github&logoColor=white alt=github style="margin-bottom: 5px;" />
<a href="https://dev.to/ther4v3n" target="_blank">
<img src=https://img.shields.io/badge/dev.to-%2308090A.svg?&style=for-the-badge&logo=dev.to&logoColor=white alt=devto style="margin-bottom: 5px;" />
</a>
<a href="https://linkedin.com/in/oliver-joisten" target="_blank">
<img src=https://img.shields.io/badge/linkedin-%231E77B5.svg?&style=for-the-badge&logo=linkedin&logoColor=white alt=linkedin style="margin-bottom: 5px;" />
</a>
<a href="https://www.facebook.com/oliver.joisten" target="_blank">
<img src=https://img.shields.io/badge/facebook-%232E87FB.svg?&style=for-the-badge&logo=facebook&logoColor=white alt=facebook style="margin-bottom: 5px;" />
</a>

</a>  
</div>
 
## Welcome! Glad to see you here  

# Singel instance Button Module
 
 ![License](https://img.shields.io/badge/license-MIT-blue.svg)
 ![Lines of code](https://tokei.rs/b1/github/The-R4V3N/single-instancemodule-button-module)

This repository contains a single-instance module called "button" that provides debounce functionality for a push button. It also includes a program (main.cpp) that utilizes the button module according to the specified requirements.
  
## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Features
- Test-Driven Development (TDD) approach
- Dual targeting strategy for high code coverage (100%)
- Enables internal pull-up resistor of the button pin
- Updates debounced state of the button with an update function
- Stable and reliable button state detection (5 consecutive states)
- Detects debounced "RELEASED" and "PRESSED" states
- Detects debounced "RISING" and "FALLING" edges
- Availability of edges within one interval
- Unique event reading for each edge

## Getting Started
  To get started with the button module, follow these steps:

  - Clone this repository to your local machine.
  - Connect a push button to pin 34 of ESP32.
  - Set up your development environment and ensure you have the necessary dependencies installed.
  
## Usage
- Include the button module in your project.
- Initialize the button module and configure it according to your requirements.
- Call the update function of the button module periodically to update the debounced state.
- Utilize the button module's functions to detect button states, edges, and perform necessary actions based on them.

 ## Testing
 To build and run the tests for the button module, you can use cmake. Here's how:
 -Make sure you have cmake installed on your system.
- Open a terminal and navigate to the project directory.
- Create a build directory:
 
 ```
 mkdir build
 cd build
 ```
 Generate the build files with cmake:

 ```
 cmake ..
```
 Build and run the test:
 
 ```
 make coverage_test_button
 ```
 The Unity tests will be executed, and you will see the test results in the terminal. and when you open the build folder you will see a index.html file  Ensure that all the tests pass successfully.
 
## Contributing
Contributions are welcome! If you have any ideas, suggestions, or improvements, please open an issue or submit a pull request.

## License
This project is licensed under the MIT License. Feel free to use and modify the code according to the terms of the license.
  
- 👨‍💻 All about me is at [My Website](https://www.oliver-joisten.se/)

<div align="center">
<img src="https://komarev.com/ghpvc/?username=the-r4v3n&&style=flat-square" align="center" />
&emsp;
<a href="https://paypal.me/paypal.me/TheR4V3N" target="_blank" style="display: inline-block;">
<img src="https://img.shields.io/badge/Donate-PayPal-blue.svg?style=flat-square&logo=paypal" align="center"/>
  
