from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""

    lines_a = set(a.split('\n'))
    lines_b = set(b.split('\n'))
    return list(lines_a.intersection(lines_b))


def sentences(a, b):
    """Return sentences in both a and b"""

    sentences_a = set(sent_tokenize(a))
    sentences_b = set(sent_tokenize(b))
    return list(sentences_a.intersection(sentences_b))


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    subs_a = set(([a[i:i+n] for i in range(0, len(a)- n + 1)]))
    subs_b = set(([b[i:i+n] for i in range(0, len(b)- n + 1)]))
    return subs_a & subs_b
