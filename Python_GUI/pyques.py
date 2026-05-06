import tkinter as tk

# 1. THE BRAIN (What happens when we click the button)
def do_addition():
    try:
        # Get text from box 1 and box 2, and turn them into numbers
        num1 = float(box1.get())
        num2 = float(box2.get())
        
        # Add them together
        answer = num1 + num2
        
        # Show the answer on the screen
        label.config(text="Answer: " + str(answer))
    except:
        # If the user typed letters instead of numbers, show an error
        label.config(text="Error: Type numbers only!")

# 2. THE BODY (Building the app window)
root = tk.Tk()
root.title("Addition Machine")
root.geometry("300x200")

# 3. THE PARTS (Creating boxes and buttons)
tk.Label(root, text="Number 1:").pack()
box1 = tk.Entry(root)
box1.pack()

tk.Label(root, text="Number 2:").pack()
box2 = tk.Entry(root)
box2.pack()

# The button that starts the math
add_button = tk.Button(root, text="Calculate Total", command=do_addition)
add_button.pack(pady=10)

# The place where the answer will appear
label = tk.Label(root, text="Answer: ", font=("Arial", 12, "bold"))
label.pack()

# 4. THE ON-SWITCH
root.mainloop()