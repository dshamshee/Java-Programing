<?php
// Member Class
class Member {
    protected $username;
    protected $email;
    protected $password;

    // Constructor to initialize member details
    public function __construct($username, $email, $password) {
        $this->username = $username;
        $this->email = $email;
        $this->password = $password;
    }

    // Method to create a post
    public function createPost($postContent) {
        // In a real application, this would save the post to a database
        echo "<h3>{$this->username} created a post:</h3>";
        echo "<p>{$postContent}</p>";
    }

    // Method to edit profile
    public function editProfile($newEmail, $newPassword) {
        $this->email = $newEmail;
        $this->password = $newPassword;
        echo "<p>Profile updated for {$this->username}</p>";
    }

    // Method to show profile
    public function showProfile() {
        echo "<h3>Profile of {$this->username}</h3>";
        echo "<p>Email: {$this->email}</p>";
        // Never display password for security purposes
    }

    // Method for logging in
    public function login($username, $password) {
        if ($this->username == $username && $this->password == $password) {
            echo "<p>Welcome, {$this->username}!</p>";
            return true;
        }
        echo "<p>Invalid credentials.</p>";
        return false;
    }

    // Method for logging out
    public function logout() {
        echo "<p>{$this->username} logged out.</p>";
    }
}

// Administrator Class (Child of Member Class)
class Administrator extends Member {
    // Constructor
    public function __construct($username, $email, $password) {
        parent::__construct($username, $email, $password);
    }

    // Method to create a forum
    public function createForum($forumName) {
        echo "<h3>Forum '{$forumName}' created by Administrator {$this->username}</h3>";
    }

    // Method to delete a forum
    public function deleteForum($forumName) {
        echo "<h3>Forum '{$forumName}' deleted by Administrator {$this->username}</h3>";
    }

    // Method to ban a member
    public function banMember($memberUsername) {
        echo "<p>Member {$memberUsername} has been banned by Administrator {$this->username}.</p>";
    }

    // Overriding login method
    public function login($username, $password) {
        if ($this->username == $username && $this->password == $password) {
            echo "<p>Welcome, Administrator {$this->username}!</p>";
            return true;
        }
        echo "<p>Invalid admin credentials.</p>";
        return false;
    }

    // Overriding logout method
    public function logout() {
        echo "<p>Administrator {$this->username} logged out.</p>";
    }
}
?>
