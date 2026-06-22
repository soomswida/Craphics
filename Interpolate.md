# Goal

The current state of dynamic graph has undersampline issue, namely, the dots cannot reprensents the graph enough because of its strict policy determining its output(in other words, dots). 

To deal with it, a simple approximation logic will be implemented here. 

- Dots strictly fitting the prior condition : '#'
- Dots approximately(seemingly) fitting the geometry : '*'

# What on earth does 'approximately fitting' mean?

In order to implement the plan above, we need firstly to set a threshold to state whether a dot is close enough to the geometry to be printed. 

# myBuffer is not enough!

`myBuffer.c`, in its nature, fundamentally assumes a printed graph is a single 'thread', but like we said, this 'single thread' approach cannot avoid the undersampling issue above. 

But in the big picture, the very idea of 'buffer' is absolutely valid, the problem is its shape(1-dim). So the solution is simple, we need to expand myBuffer in 2-dim shape.  
