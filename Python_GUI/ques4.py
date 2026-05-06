import tkinter as tk
import sqlite3

conn = sqlite3.connect("tasks.db")
cur = conn.cursor()

cur.execute("CREATE TABLE IF NOT EXISTS tasks(task TEXT)")
conn.commit()

def add_task():
    task = entry.get()
    if task:
        cur.execute("INSERT INTO tasks VALUES(?)", (task,))
        conn.commit()
        listbox.insert(tk.END, task)
        entry.delete(0, tk.END)

def delete_task():
    selected = listbox.curselection()
    if selected:
        task = listbox.get(selected)
        cur.execute("DELETE FROM tasks WHERE task=?", (task,))
        conn.commit()
        listbox.delete(selected)

root = tk.Tk()
root.title("Task Manager")
root.geometry("400x500")  # Increased window size

entry = tk.Entry(root, width=40, font=("Arial", 12))
entry.pack(pady=10)

tk.Button(root, text="Add Task", command=add_task, width=20, height=2).pack(pady=5)

listbox = tk.Listbox(root, width=40, height=15, font=("Arial", 10))
listbox.pack(pady=10)

tk.Button(root, text="Delete Task", command=delete_task, width=20, height=2).pack(pady=5)

root.mainloop()