def modified(s, exe):
    for c in s:
        if not c.isalnum():
            s = s.replace(c, " ")
    s = s[0].upper() + s[1:]
    big = False
    name = ""
    for c in s:
        if c == " ":
            big = True
        elif big:
            name += c.upper()
            big = False
        else:
            name += c

    return name + "." + exe


def create(s, exe):
    s = modified(s, extention)
    import os
    if not os.path.exists(s):
        open(s, 'x').close()
    else:
        print(f"File {s} already exists")
    os.system(f"code {s}")


name = "cpp files name"

extention = "cpp"

create(name, extention)
