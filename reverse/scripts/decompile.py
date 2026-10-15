# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2026 The mtk-thermal-re Authors
#
# PyGhidra harness: decompile specific functions from the target binaries.
# Usage: python decompile.py <binary> 0xVMA:symbol [0xVMA:symbol ...]
# NOTE: pyghidra.start() must run before any ghidra.* import.
import sys, pyghidra
pyghidra.start()
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

BIN = sys.argv[1]
TARGETS = {int(x, 0): n for x, n in (pair.split(':') for pair in sys.argv[2:])}

with pyghidra.open_program(BIN, analyze=True) as fa:
    program = fa.getCurrentProgram()
    base = program.getImageBase()
    print("IMAGE_BASE", base)
    ifc = DecompInterface()
    ifc.openProgram(program)
    mon = ConsoleTaskMonitor()
    fm = program.getFunctionManager()
    for vma, name in TARGETS.items():
        addr = base.add(vma)
        func = fm.getFunctionContaining(addr)
        if func is None:
            # create
            try:
                func = fa.createFunction(addr, name)
            except Exception as e:
                print("=== %s (%#x) NO FUNCTION: %s" % (name, vma, e))
                continue
        res = ifc.decompileFunction(func, 60, mon)
        c = res.getDecompiledFunction().getC() if res and res.getDecompiledFunction() else "  <decompile failed>"
        print("\n//======================= %s @ %#x =======================//" % (name, vma))
        print(c)
