import tkinter as tk
import sqlite3

conn = sqlite3.connect("users.db")
cur = conn.cursor()

cur.execute("CREATE TABLE IF NOT EXISTS users(username TEXT, password TEXT)")
conn.commit()

def signup():
    user = entry_user.get()
    pwd = entry_pass.get()
    cur.execute("INSERT INTO users VALUES(?, ?)", (user, pwd))
    conn.commit()
    status.config(text="Signup Successful")

def login():
    user = entry_user.get()
    pwd = entry_pass.get()
    cur.execute("SELECT * FROM users WHERE username=? AND password=?", (user, pwd))
    result = cur.fetchone()
    if result:
        status.config(text="Login Successful")
    else:
        status.config(text="Invalid Credentials")

root = tk.Tk()
root.title("Login System")
root.geometry("300x200")  

tk.Label(root, text="Username").pack()
entry_user = tk.Entry(root)
entry_user.pack()

tk.Label(root, text="Password").pack()
entry_pass = tk.Entry(root, show="*")
entry_pass.pack()

tk.Button(root, text="Signup", command=signup).pack()
tk.Button(root, text="Login", command=login).pack()

status = tk.Label(root, text="")
status.pack()

root.mainloop()