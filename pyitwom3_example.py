import pyitwom3 as itwom

print ("Using ITWOM Version: {}".format(itwom.ITWOMVersion()))

# allocate native array
elev = itwom.doubleArray(4)

# copy elevation data from python list into native array
x=[1.0, 70.0, 165.0, 166.0]
for i in range(len(x)):
	elev[i] = x[i]

# create native pointers for outputs
errnum = itwom.intp()
loss = itwom.doublep()

# strmode is wrapped by swig and the value returned from the function call
mode = itwom.point_to_point(elev, 
	7.62, 6.09, 15, 0.005, 301, 900, 5, 0, 0.5, 0.5, 
	loss, errnum)

# access native pointer values.
print("dbloss: {:8.2f}, mode: {}, errno: {}".format(itwom.doublep.value(loss), mode, 
			itwom.intp.value(errnum)))

# check result.
assert (abs(itwom.doublep.value(loss) - 90.44) < 0.01)
