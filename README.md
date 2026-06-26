# CI Raspberry Martin

Dieses Repository demonstriert eine vollständige CI-Pipeline für ein gemischtes C/Python-Projekt,
das einen typischen Embedded-Workflow (Raspberry Pi) nachbildet.

---

## Projektstruktur

```
ci_raspberry_martin/
├── c/
│   ├── include/math_utils.h    # öffentliche API
│   ├── src/math_utils.c        # Implementierung
│   ├── tests/test_math_utils.c
│   └── CMakeLists.txt
├── python/
│   ├── src/mathutils/math_utils.py
│   ├── tests/test_math_utils.py
│   ├── pyproject.toml
│   └── requirements.txt
├── .github/workflows/ci.yml
└── Makefile
```

---

## Make-Targets

| Target       | Beschreibung |
|--------------|--------------|
| `make build` | Konfiguriert und baut den C-Teil mit CMake; installiert Python-Abhängigkeiten |
| `make test`  | Führt C-Unit-Tests (Unity via ctest) und Python-Tests (pytest) aus |
| `make check` | Statische Analyse: cppcheck für C, Ruff für Python |
| `make clean` | Entfernt alle Build-Artefakte (`c/build/`) |
| `make all`   | Führt `build`, `test` und `check` nacheinander aus |

---

## Lokales Bauen und Testen

### Voraussetzungen

- CMake ≥ 3.16
- C-Compiler (GCC oder MSVC)
- Python ≥ 3.9
- cppcheck

### C-Teil bauen und testen

```bash
cmake -S c -B c/build
cmake --build c/build
cd c/build && ctest -C Debug --output-on-failure
```

CMake lädt **Unity** (C-Test-Framework) automatisch via `FetchContent` herunter –
kein manuelles Installieren nötig, aber Internetverbindung beim ersten Build erforderlich.

### Python-Teil testen

```bash
pip install -r python/requirements.txt -e python/
cd python && pytest tests/ -v
cd python && ruff check src/
```

### Alles auf einmal (Linux/macOS)

```bash
make all
```

> **Hinweis:** `make` funktioniert nur unter Linux/macOS. Unter Windows die
> cmake/pytest-Befehle direkt verwenden (siehe oben).

---

## Continuous Integration

Der GitHub Actions Workflow (`.github/workflows/ci.yml`) läuft bei jedem
Push auf `main` und bei jedem Pull Request automatisch:

| Job | Schritte |
|-----|---------|
| **C – Build, Test, Static Analysis** | Install tools → CMake Build → ctest → cppcheck |
| **Python – Lint, Test** | Install deps → ruff check → pytest |

Nur PRs mit grüner CI können in `main` gemergt werden (Branch Protection).

---

## Abhängigkeiten

- **C-Tests:** [Unity](https://github.com/ThrowTheSwitch/Unity) v2.6.0 – wird automatisch via CMake `FetchContent` heruntergeladen
- **Python-Tests:** pytest, ruff – via `python/requirements.txt`
