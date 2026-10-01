This console application takes beam properties defined by the user and displays the
results of the moment, shear and torsion.

# INSTRUCTIONS:

- You are required to write a program that calculates the properties of a rectangular concrete beam.
- The program should receive the required input from the user to calculate and display the results of the moments, shear, and torsion.
- The user should be able to save and load input data to and from a file.
- You are free to choose a language, with the following requirements in mind:
    - The beam should be represented by a class, and object-oriented programming should be used.
- The calculations should be based on Eurocode or SANS.
- When done, share your solution on GitHub.

# REQUIREMENTS:

- This application runs in a C++ environment.
- The Matplotlib library is used to plot the results. This means that you may need to install Python, Numpy and Matplotlib to your
local system, if not already installed, and link them to your compiler to successfully run the application from your local machine.

# EXAMPLE:

### Input:
```
Do you want to load input from file? [Y/N]: n

Enter Beam Properties Below
Sign convention: Upwards (+ve), Downwards (-ve)

depth (mm): 450

width (mm): 220

length (mm): 3000

point load, P (kN): -5

P location (mm): 1500

uniformly distributed load, w (kN/m): -2

torsional moment, T (kNm): 3

T location (mm): 2000

type of support (simple[s]/fixed[f]): s

self-weight (kN/m3): -24

Do you want to save the input data to file? [Y/N]: n
```
### Results:
<img width="640" height="480" alt="Figure_1" src="https://github.com/user-attachments/assets/513cd6b0-7a60-4066-a399-08e47aef2d46" />
