#!/usr/bin/env python3
"""
Comment stripping tool for learning/practice copies.

Removes:
    // line comments
    /* block comments */

Preserves:
    strings
    character literals
    newlines (for readable diffs)
"""

from pathlib import Path
import sys

# ---------- parser states ----------
NORMAL = 0
SLASH = 1
LINE_COMMENT = 2
BLOCK_COMMENT = 3
BLOCK_COMMENT_STAR = 4
DQUOTE = 5
SQUOTE = 6
DQUOTE_ESCAPE = 7
SQUOTE_ESCAPE = 8


def strip_comments(text: str) -> str:
    out = []
    state = NORMAL

    for ch in text:
        if state == NORMAL:
            if ch == '/':
                state = SLASH
            elif ch == '"':
                out.append(ch)
                state = DQUOTE
            elif ch == "'":
                out.append(ch)
                state = SQUOTE
            else:
                out.append(ch)

        elif state == SLASH:
            if ch == '/':
                state = LINE_COMMENT
            elif ch == '*':
                state = BLOCK_COMMENT
            else:
                out.append('/')
                out.append(ch)
                state = NORMAL

        elif state == LINE_COMMENT:
            if ch == '\n':
                out.append('\n')
                state = NORMAL

        elif state == BLOCK_COMMENT:
            if ch == '*':
                state = BLOCK_COMMENT_STAR
            elif ch == '\n':
                out.append('\n')

        elif state == BLOCK_COMMENT_STAR:
            if ch == '/':
                state = NORMAL
            elif ch == '\n':
                out.append('\n')
                state = BLOCK_COMMENT
            else:
                state = BLOCK_COMMENT

        elif state == DQUOTE:
            out.append(ch)
            if ch == '\\':
                state = DQUOTE_ESCAPE
            elif ch == '"':
                state = NORMAL

        elif state == DQUOTE_ESCAPE:
            out.append(ch)
            state = DQUOTE

        elif state == SQUOTE:
            out.append(ch)
            if ch == '\\':
                state = SQUOTE_ESCAPE
            elif ch == "'":
                state = NORMAL

        elif state == SQUOTE_ESCAPE:
            out.append(ch)
            state = SQUOTE

    if state == SLASH:
        out.append('/')

    return ''.join(out)


def process_file(input_path: Path, output_path: Path):
    if not input_path.exists():
        print(f"Skipping (not found): {input_path}")
        return

    output_path.parent.mkdir(parents=True, exist_ok=True)

    text = input_path.read_text(encoding="utf-8")
    cleaned = strip_comments(text)

    output_path.write_text(cleaned, encoding="utf-8", newline="\n")

    print(f"Created practice file:")
    print(f"   IN : {input_path}")
    print(f"   OUT: {output_path}")
    print()


def main():
    # ---- project assumptions ----
    project_name = "Slash3"

    root = Path.cwd()

    cpp_in = root / "Source" / project_name / "Private" / "Item.cpp"
    h_in   = root / "Source" / project_name / "Public"  / "Item.h"

    practice_dir = root / "Practice"

    cpp_out = practice_dir / "Item.practice.cpp"
    h_out   = practice_dir / "Item.practice.h"

    process_file(cpp_in, cpp_out)
    process_file(h_in, h_out)

    print("Done. Practice versions ready.")


if __name__ == "__main__":
    main()