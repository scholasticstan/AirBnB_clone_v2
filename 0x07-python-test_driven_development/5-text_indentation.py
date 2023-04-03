def text_indentation(text):
    if not isinstance(text, str):
        raise TypeError("text must be a string")

    punctuation = [".", "?", ":"]
    lines = []
    line = ""

    for char in text:
        if char in punctuation:
            lines.append(line.strip())
            lines.append("")
            line = ""
        else:
            line += char

    if line:
        lines.append(line.strip())

    for line in lines:
        print(line)

