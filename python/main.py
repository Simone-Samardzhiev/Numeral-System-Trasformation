from tkinter import *
from functions import *

choice_1 = ''
choice_2 = ''


def create_window() -> Tk:
    def on_select_list_1(event):
        if list_1.curselection():
            global choice_1
            choice_1 = list_1.get(list_1.curselection())

    def on_select_list_2(event):
        if list_2.curselection():
            global choice_2
            choice_2 = list_2.get(list_2.curselection())

    def transform() -> None:
        num = ent.get()
        match choice_1:
            case 'binary':
                if is_binary(num):
                    match choice_2:
                        case 'octal':
                            lb.config(text=binary_to_octal(num))
                        case 'decimal':
                            lb.config(text=binary_to_decimal(num))
                        case 'hexadecimal':
                            lb.config(text=binary_to_hexadecimal(num))
                else:
                    lb.config(text="Enter a valid input")
            case 'octal':
                if is_octal(num):
                    match choice_2:
                        case 'binary':
                            lb.config(text=octal_to_binary(num))
                        case 'decimal':
                            lb.config(text=octal_to_decimal(num))
                        case 'hexadecimal':
                            lb.config(text=octal_to_hexadecimal(num))
                else:
                    lb.config(text="Enter a valid input")
            case 'decimal':
                if is_decimal(num):
                    match choice_2:
                        case 'binary':
                            lb.config(text=decimal_to_binary(num))
                        case 'octal':
                            lb.config(text=decimal_to_octal(num))
                        case 'hexadecimal':
                            lb.config(text=decimal_to_hexadecimal(num))
                else:
                    lb.config(text="Enter a valid input")
            case 'hexadecimal':
                if is_hexadecimal(num):
                    match choice_2:
                        case 'binary':
                            lb.config(text=hexadecimal_to_binary(num))
                        case 'octal':
                            lb.config(text=hexadecimal_to_octal(num))
                        case 'decimal':
                            lb.config(text=hexadecimal_to_decimal(num))
                else:
                    lb.config(text="Enter a valid input")

    wnd = Tk()
    wnd.geometry("1000x500")
    wnd.title("Numeral system transformation")

    ent = Entry(wnd)
    ent.grid(row=0, column=0, pady=10, padx=10, sticky="nw")

    lb = Label(wnd, text="")
    lb.grid(row=0, column=3, pady=10, padx=10, sticky="ne")

    options = ['decimal', 'hexadecimal', 'binary', 'octal']
    list_1 = Listbox(wnd, selectmode=SINGLE)
    list_1.grid(row=1, column=0, padx=10, pady=10, sticky="nw")
    list_1.bind("<<ListboxSelect>>", on_select_list_1)

    list_2 = Listbox(wnd, selectmode=SINGLE)
    list_2.grid(row=1, column=3, padx=10, pady=10, sticky="ne")
    list_2.bind("<<ListboxSelect>>", on_select_list_2)

    btn = Button(wnd, text="Transform", command=transform)
    btn.grid(row=2, column=1, pady=10, padx=10, sticky="nsew")

    for item in options:
        list_1.insert(END, item)
        list_2.insert(END, item)

    return wnd


def main() -> None:
    wnd = create_window()
    wnd.mainloop()


if __name__ == "__main__":
    main()
