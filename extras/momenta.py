#!/usr/bin/env python3

momenta = []
lmax = 4
for l in range(lmax + 1):
    for lx in reversed(range(l + 1)):
        for ly in reversed(range(l + 1 - lx)):
            lz = l - lx - ly
            momenta.append((lx, ly, lz))

print("Momenta:")
for index, momentum in enumerate(momenta):
    print(f"{index}: {momentum}")
'''
def calculate_position_after_decrement(tuple_in):
    lx, ly, lz = tuple_in

    # Calculate the position using the formula
    position = lx * (lx + 1) // 2 + ly

    if lx > 0:
        position -= 1

    return position

# Example usage
tuple_in = (2, 1, 1)
position_after_decrement = calculate_position_after_decrement(tuple_in)
print(position_after_decrement)
'''
