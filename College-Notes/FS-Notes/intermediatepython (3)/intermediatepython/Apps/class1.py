class circle:
  count = 0
  def __init__(self, radius, color='Blue'):
    self.radius = radius
    self.color=color
    circle.count += 1
    print("__init__ called")

obj = circle(5, 'green')
print(obj.radius)
print(obj.color)
obj2 = circle(10)
print(obj2.color)
print(circle.count)
