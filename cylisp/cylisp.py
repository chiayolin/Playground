def tokenize(prog):
    return prog.replace('(', ' ( ').replace(')', ' ) ').split()

# TODO: this atom function is broken
def atom(token):
    if type(token) == int: return int(token)
    elif type(token) == float: return float(token)
    else: return str(token)

# TODO: fix error checking style
# return values:
#   * a list of s-expression on success 
#   * -1 on unmatched open paren(s)
#   * 1 on unmatched close paren(s)
#
def parse(tokens):
    def _parse_sexp(tokens, in_paren):
        result = list()
        while len(tokens) != 0:
            if tokens[0] == '(':
                # pop off '(' and append a list recursively
                tokens.pop(0) 
                result.append(_parse_sexp(tokens, True))
            elif tokens[0] == ')':
                return in_paren and result or 1
            else:
                result.append(atom(tokens[0]))
            
            len(tokens) != 0 and tokens.pop(0)

        return not in_paren and result or None
    
    sexp_list = _parse_sexp(tokens, False)
    return type(sexp_list) is list and None in sexp_list and -1 or sexp_list

# this repl is just a prototype
def repl():
    while True:
        tree = parse(tokenize(input("> ")))
        if tree == None: 
            continue
        elif type(tree) != list:
            print("Error: Unmatched", 
                tree < 0 and "open" or "closed", "paren(s)")
        else:
            print(tree)

repl()
