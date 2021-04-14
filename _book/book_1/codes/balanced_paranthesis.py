"""
Check if the given string has balanced parantheses

balanced('(())())()') -> False
balanced('(())(())') -> True
"""

# first implementation
def balanced(s):
    # counting the number of left '('
    left = '('
    right = ')'
    return s.count(left) == s.count(right)


if __name__ == "__main__":
    assert balanced('(())()')
    assert not balanced('(((((')
    assert balanced('()()()')
