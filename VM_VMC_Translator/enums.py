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

    Eq = 'Eq'
    Lt = 'Lt'
    Gt = 'Gt'
    Ge = 'Ge'
    Le = 'Le'
    Neq = 'Neq'

    Add = 'Add'
    Sub = 'Sub'
    LShift = 'LShift'
    RightShift = 'RShift'
    BitAnd = 'BitAnd'
    BitOr = 'BitOr'
    BitXor = 'BitXor'


class Segment(enum.Enum):
    local = 'local'
    argument = 'argument'
    constant = 'constant'
    temp = 'temp'


class Datatypes(enum.Enum):
    INT = 'INT'
    FLOAT = 'FLOAT'
    BOOL = 'BOOL'
    CHAR = 'CHAR'
    STR = 'STR'


class Operators(enum.Enum):
    Plus = '+'
    Minus = '-'
    Mul = '*'
    Div = '/'
    Mod = '%'
    BitAnd = '&'
    BitOr = '|'
    BitXor = '^'
    LeftShift = '<<'
    RightShift = '>>'
    LogicalAnd = '&&'
    LogicalOr = '||'
    Gt = ['bgt','flt.s','special']
    Lt = ['blt', 'flt.s']
    Ge = ['bge','fle.s','special']
    Le = ['ble', 'fle.s']
    Eq = ['beq', 'feq.s']
