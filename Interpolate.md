# Goal

The current state of dynamic graph has undersampling issue, namely, the dots cannot reprensent the graph enough because of its strict policy determining its output(printed dots). 

To deal with it, a simple approximation logic will be implemented here. 

- Dots strictly fitting the prior condition : '#'
- Dots approximately(seemingly) fitting the geometry : '*'

# What on earth does 'approximately fitting' mean?

In order to implement the plan above, we need firstly to set a threshold to state whether a dot is close enough to the geometry to be printed. 

# myBuffer is not enough!

`myBuffer.c`, in its nature, fundamentally assumes a printed graph is a single 'thread', but like we said, this 'single thread' approach cannot avoid the undersampling issue above. 

But in the big picture, the very idea of 'buffer' is absolutely valid, the problem is its shape(1-dim). So the solution is simple, we need to expand myBuffer in 2-dim shape. 

# Overall Plan

**(0) Expand myBuffer to 2-dimensional matrix shape

**(1) Make a dedicated function for sampling from the geometry**

- In single-thread approach, this kind of dedicated function does not required, because the algebraic function itself was playing the role of it. 

- But multi-thread(approximation) approach cannot employ this approach, it requires a function to:

1. compute the result with the given algebraic expression and add it onto the buffer
2. add the interpolating dots onto the buffer 

**(2) Modify drawTrajectory() to cover 2-dim buffer (minor)**
