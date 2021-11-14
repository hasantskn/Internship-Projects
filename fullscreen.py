import tkinter as tk

class Fullscreen_Example:
    
    def __init__(self):
        self.window = tk.Tk()
        self.window.attributes('-fullscreen', True)  
        self.fullScreenState = False
        #self.window.bind("<F11>", self.toggleFullScreen)
        #self.window.bind("<Escape>", self.quitFullScreen)
        self.window.bind("<Control-c>",self.close_window)
        self.window.protocol("WM_DELETE_WINDOW",self.disable_event)


        self.window.mainloop()

    def toggleFullScreen(self, event):
        self.fullScreenState = not self.fullScreenState
        self.window.attributes("-fullscreen", self.fullScreenState)

    def quitFullScreen(self, event):
        self.fullScreenState = False
        self.window.attributes("-fullscreen", self.fullScreenState)
    def close(self, *event):
        self.window.destroy()
    
    def close_window(self,*event):
       self.window.destroy()
       
       
    def disable_event(self,*event):
       pass
   

            
   
    
       


if __name__ == '__main__':
    app = Fullscreen_Example()