import enum


class Instructions(enum.Enum):
    push = 'push'
    pop = 'pop'
    function = 'function'
    label = 'label'
    goto = 'goto'
    ret = 'return'
    if_goto = 'if-goto'
    print_stmt = 'print'
    call = 'call'
    scan = 'scan'

    Eq = 'eq'
    Lt = 'lt'
    Gt = 'gt'
    Ge = 'ge'
    Le = 'le'
    Neq = 'neq'
    Not = 'not'

    Add = 'add'
    Sub = 'sub'
    LShift = 'lshift'
    RShift = 'rshift'
    BitAnd = 'and'
    BitOr = 'or'
    BitXor = 'xor'


class Segment(enum.Enum):
    local = 'local'
    argument = 'argument'
    constant = 'constant'
    temp = 'temp'
    that = 'that'
    data = 'data'


class Datatypes(enum.Enum):
    INT = 'INT'
    FLOAT = 'FLOAT'
    BOOL = 'BOOL'
    CHAR = 'CHAR'
    STR = 'STR'


class Operators(enum.Enum):
    Add = ['add', 'fadd.s']
    Sub = ['sub', 'fsub.s']
    LShift = ['sll']
    RShift = ['srl']
    BitAnd = ['and']
    BitOr = ['or']
    BitXor = ['xor']

    Plus = '+'
    Minus = '-'
    Mul = '*'
    Div = '/'
    Mod = '%'

    LeftShift = '<<'
    RightShift = '>>'
    LogicalAnd = '&&'
    LogicalOr = '||'
    Gt = ['bgt', 'flt.s', 'special']
    Lt = ['blt', 'flt.s']
    Ge = ['bge', 'fle.s', 'special']
    Le = ['ble', 'fle.s']
    Eq = ['beq', 'feq.s']
