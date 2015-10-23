def printargs(func):
  def wrapper(*ar, **rgs):
    print ar
    ret = func(*ar, **rgs)
    ret = sorted(ret)
    return ret
  return wrapper

@printargs
def add(a, b):
  return a + b

@printargs
def hello(a , b, c):
  print a, b, c

def test(y, x = None):
  print x, y

hello([232,323,42,34,23], {"helo":"workd"}, "helloworst")
