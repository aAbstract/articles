def manual_cffi():
    import ctypes
    module = ctypes.CDLL('./module.so')  # load library
    module.add_nums.argtypes = [ctypes.c_int, ctypes.c_int]  # define input arguments
    module.add_nums.restype = ctypes.c_int  # define return type
    print('module.add_nums(3, 4) =>', module.add_nums(3, 4))


def ctypesgen_cffi():
    from module_ffi import _libs
    module = _libs['module.so']
    module.add_nums(3, 4)
    print('module.add_nums(3, 4) =>', module.add_nums(3, 8))


ctypesgen_cffi()
