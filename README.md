# initial-value-problem

Graphical representation of a 1-dimensional first order ordinary differential equation, expressed in the form

y'(x) = f(x,y(x))

There are two main parts:
* the first approximates the initial value problem using Runge-Kutta4 method for a list of many different initial values of the form y(0) = y_0
* the second uses ROOT\CERN to draw a representation of the vector field

	F: (x,y) -> (x,f(x,y))

  associated to the ODE.
  It also overlays the solutions obtained by the Runge-Kutta4 method onto the vector field.

## Usage

Set the parameters of the system in

* `./CauchyProblem/CauchyProblem.c`
* `./parameters.h`

Compile the code with `./compile.sh`
Run the code with `./run.sh`

## Status

This programs have been written to have a better understanding of the
initial value problems while studying for the Advanced Calculus
course. The correct output has been considered as the only measure
to assert the quality of the code, which in result is far from
being clean and optimized and may contain some not-so-nice workarounds.
I may consider to upgrade it in a remote future.
