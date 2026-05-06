import tkinter as tk

root = tk.Tk()
root.title("My Window")
root.geometry("400x300")   # width x height
root.resizable(False, False)  # fixed size

label = tk.Label(root, text="Hello, Tkinter!", font=("Arial", 14))
label.pack(pady=50)

root.mainloop()