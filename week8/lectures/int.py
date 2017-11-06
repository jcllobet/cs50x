#prompt user for x
import cs50

print("x is ", end="")
x = cs50.get_int()

#promt user for y
print("y is ", end="")
y = cs50.get_int()

#perform calculations for user
print("{} plus {} is {}".format(x, y, x + y ))
print("{} minus {} is {}".format(x, y, x - y ))
print("{} times {} is {}".format(x, y, x * y ))
print("{} divided {} is {}".format(x, y, x / y ))
print("{} divided {} (and floored)is {}".format(x, y, x // y ))
print("remainder of{} divided by {} is {}".format(x, y, x %  y ))
