# The growth and decay of members of a radioactive series

C++ Academic project (2017)

In nuclear physics, the Bateman equation is a mathematical model describing abundances and 
activities in a decay chain as a function of time, based on the decay rates and initial abundances.


## Basic knowledge for the Bateman model

The solution of these equations leads to a general form for the activity of the n'th daughter in a series at any given time.

This equation may be applied until the half-life of one of the daughters approaches or exceeds that of the first member of the series. (It is not necessary that each daughter be shorter lived than the one preceding it.)

Read [this document](http://www.ripphysics.com/EPA_RadNet/BatemanEquations.pdf) page 7 to understand the content of radon222.txt
Basically, radon222.txt describes the major radiations of radon-222 and daughters.

## How to

Clone the repository in a chosen path

```cd ~/path/...```

```git clone https://github.com/Guilyx/bateman-equations-project.git```

Compile the C++ project (might add a Cmake to build later on)

```g++ -o execute *.cpp```

Execute with:

```./execute```

## Architecture

...UC

## Licence

[BSD 3-Clause License](https://github.com/Guilyx/bateman-equations-project/blob/master/LICENSE)
