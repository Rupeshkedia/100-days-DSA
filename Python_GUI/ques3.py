import tkinter as tk
import sqlite3

conn = sqlite3.connect("students.db")
cur = conn.cursor()

cur.execute("CREATE TABLE IF NOT EXISTS students(name TEXT, course TEXT)")
conn.commit()

def register():
    name = entry_name.get()
    course = entry_course.get()
    cur.execute("INSERT INTO students VALUES(?, ?)", (name, course))
    conn.commit()
    entry_name.delete(0, tk.END)
    entry_course.delete(0, tk.END)

root = tk.Tk()
root.title("Student Registration")

tk.Label(root, text="Name").grid(row=0, column=0)
entry_name = tk.Entry(root)
entry_name.grid(row=0, column=1)

tk.Label(root, text="Course").grid(row=1, column=0)
entry_course = tk.Entry(root)
entry_course.grid(row=1, column=1)

tk.Button(root, text="Register", command=register).grid(row=2, column=0, columnspan=2)

root.mainloop()