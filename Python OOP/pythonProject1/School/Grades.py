class Grade:
    def __init__(self, subject, value):
        self.subject = subject
        self.value = value

    def get_grade_info(self):
        return f"Subject: {self.subject}, Grade: {self.value}"
