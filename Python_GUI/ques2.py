import tkinter as tk

def click(value):
    entry.insert(tk.END, value)

def clear():
    entry.delete(0, tk.END)

def calculate():
    try:
        result = eval(entry.get())
        entry.delete(0, tk.END)
        entry.insert(0, str(result))
    except:
        entry.delete(0, tk.END)
        entry.insert(0, "Error")

root = tk.Tk()
root.title("Calculator")

entry = tk.Entry(root, width=20, font=("Arial", 16))
entry.grid(row=0, column=0, columnspan=4)

buttons = [
    '7','8','9','/',
    '4','5','6','*',
    '1','2','3','-',
    '0','.','=','+'
]

for i, text in enumerate(buttons):
    row, col = i//4 + 1, i%4
    if text == "=":
        tk.Button(root, text=text, command=calculate).grid(row=row, column=col)
    else:
        tk.Button(root, text=text, command=lambda t=text: click(t)).grid(row=row, column=col)

tk.Button(root, text="C", command=clear).grid(row=5, column=0, columnspan=4, sticky="nsew")
root.mainloop()