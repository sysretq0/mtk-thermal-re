# SPDX-License-Identifier: GPL-3.0-or-later
# Makefile for mtk-thermal-re.  Run `make` or `make help` for targets.

PYTHON  ?= python3
PKG      = mtk_thermal_re
SRC      = src
TESTS    = tests
DIST     = dist
PYTEST   ?= $(PYTHON) -m pytest

.PHONY: help test test-verbose lint fmt typecheck install build clean dist re venv

help: ## Show this help
	@grep -E '^[a-zA-Z0-9_-]+:.*?## .*$$' $(MAKEFILE_LIST) \
		| sort | awk 'BEGIN {FS = ":.*?## "}; {printf "  \033[36m%-14s\033[0m %s\n", $$1, $$2}'

venv: ## Create a local virtualenv in .venv
	$(PYTHON) -m venv .venv
	./.venv/bin/python -m pip install --upgrade pip
	./.venv/bin/python -m pip install -e '.[dev]'

test: ## Run the test suite (stdlib unittest, no extra deps)
	PYTHONPATH=$(SRC) $(PYTHON) -m unittest discover -s $(TESTS) -v

test-quiet: ## Run the test suite quietly
	PYTHONPATH=$(SRC) $(PYTHON) -m unittest discover -s $(TESTS)

lint: ## Lint with ruff (dev extra)
	$(PYTHON) -m ruff check $(SRC) $(TESTS)

fmt: ## Format with ruff (dev extra)
	$(PYTHON) -m ruff format $(SRC) $(TESTS)
	$(PYTHON) -m ruff check --fix $(SRC) $(TESTS)

typecheck: ## Type-check with mypy if available
	$(PYTHON) -m mypy $(SRC) || echo "mypy not installed - skipping"

install: ## Install the package into the current environment
	$(PYTHON) -m pip install .

build: ## Build sdist + wheel into dist/
	$(PYTHON) -m build

dist: build ## Alias for build

clean: ## Remove build/cache artifacts
	rm -rf $(DIST) build *.egg-info .pytest_cache .ruff_cache
	find . -type d -name __pycache__ -prune -exec rm -rf {} +
	find . -type d -name '*.egg-info' -prune -exec rm -rf {} +

re: ## Re-decompile the key functions (needs pyghidra; see reverse/scripts/)
	@echo "See reverse/scripts/decompile.py -- requires pyghidra and the target binaries."
	@echo "Usage: /opt/pyghidra-venv/bin/python reverse/scripts/decompile.py <binary> 0xADDR:symbol ..."
