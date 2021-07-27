# Problem Set 4A
# Name: kana800
# Collaborators: none
# Time Spent: 13:25 

def get_permutations(sequence):
    '''
    Enumerate all permutations of a given string

    sequence (string): an arbitrary string to permute. Assume that it is a
    non-empty string.  

    You MUST use recursion for this part. Non-recursive solutions will not be
    accepted.

    Returns: a list of all permutations of sequence

    Example:
    >>> get_permutations('abc')
    ['abc', 'acb', 'bac', 'bca', 'cab', 'cba']

    Note: depending on your implementation, you may return the permutations in
    a different order than what is listed here.
    '''
    if len(sequence) == 1:
        return sequence[0]
    # list to store the results
    permutations = []
    for string in sequence:
        # getting the permutations of the
        # sublist
        permutation_sublist = get_permutations([i for i in sequence if i !=
                                                string])

        # contactnating the elements and 
        # joining them to the list
        for element in permutation_sublist:
            permutations.append(string + element)

    return permutations


if __name__ == '__main__':
#    #EXAMPLE
    example_input = 'abc'
    print('Input:', example_input)
    print('Expected Output:', ['abc', 'acb', 'bac', 'bca', 'cab', 'cba'])
    print('Actual Output:', get_permutations(example_input))

#    # Put three example test cases here (for your sanity, limit your inputs
#    to be three characters or fewer as you will have n! permutations for a 
