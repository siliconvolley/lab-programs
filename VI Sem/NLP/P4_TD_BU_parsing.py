# 4) Implement top-down and bottom-up parsing using python NLTK

import nltk
from nltk import CFG

# Define the grammar
grammar = CFG.fromstring("""
    S -> NP VP
    VP -> Aux V NP | Aux V NP PP
    PP -> P NP
    V -> "playing" | "watching"
    Aux -> "is"
    NP -> "Achal" | "Rishabh" | "Manja" | Det N | Det N PP
    Det -> "a" | "an" | "the" | "my"
    N -> "library" | "volleyball" | "table" | "park"
    P -> "in" | "on" | "by" | "with"
""")

def main():
    # Test sentence to parse
    sentence = "Achal is playing volleyball in the library"

    

if __name__ == '__main__':
    main()