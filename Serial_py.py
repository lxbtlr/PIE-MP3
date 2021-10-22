
import tkinter as tk
import Serial_cmd

class Serial_cmd_gui:

    def __init__(self):
        self.dev = Serial_cmd.Serial_cmd()
        if self.dev.dev is not None:
            self.update_job = None
            self.root = tk.Tk()
            self.root.title('Serial_cmd GUI')
            self.root.protocol('WM_DELETE_WINDOW', self.shut_down)
            fm = tk.Frame(self.root)
            tk.Button(fm, text = 'TOGGLE RED', command = self.toggle_red).pack(side = tk.LEFT)
            fm.pack(side = tk.TOP)
            green_slider = tk.Scale(self.root, from_ = 0, to = 1000, orient = tk.HORIZONTAL, showvalue = tk.FALSE, command = self.set_green_callback)
            green_slider.set(500)
            green_slider.pack(side = tk.TOP)
            yellow_slider = tk.Scale(self.root, from_ = 0, to = 1000, orient = tk.HORIZONTAL, showvalue = tk.FALSE, command = self.set_yellow_callback)
            yellow_slider.set(500)
            yellow_slider.pack(side = tk.TOP)
            self.sw1_status = tk.Label(self.root, text = 'SW1 is currently ?')
            self.sw1_status.pack(side = tk.TOP)
            self.sw2_status = tk.Label(self.root, text = 'SW2 is currently ?')
            self.sw2_status.pack(side = tk.TOP)
            self.pot_status = tk.Label(self.root, text = 'POT is currently ????')
            self.pot_status.pack(side = tk.TOP)
            self.update_job = self.root.after(500, self.update_status)

    def toggle_red(self):
        self.dev.set_red(1 - self.dev.get_red())

    def set_green_callback(self, value):
        self.dev.set_green(int(value))

    def set_yellow_callback(self, value):
        self.dev.set_yellow(int(value))

    def update_status(self):
        self.sw1_status.configure(text = 'SW1 is currently {!s}'.format(self.dev.get_sw1()))
        self.sw2_status.configure(text = 'SW2 is currently {!s}'.format(self.dev.get_sw2()))
        self.pot_status.configure(text = 'POT is currently {:04d}'.format(self.dev.get_pot()))
        self.update_job = self.root.after(50, self.update_status)

    def shut_down(self):
        if self.update_job is not None:
            self.root.after_cancel(self.update_job)
        self.root.destroy()

if __name__=='__main__':
    gui = Serial_cmd_gui()
    gui.root.mainloop()

