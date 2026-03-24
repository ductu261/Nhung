```markdown
# Hướng dẫn sử dụng Git cơ bản từ Terminal

Tài liệu này tổng hợp các lệnh Git thường dùng để quản lý source code qua terminal, từ việc thiết lập ban đầu, liên kết repository cho đến các thao tác push/pull hàng ngày. 

---

## 1. Cấu hình ban đầu (Chỉ làm 1 lần)

Trước khi bắt đầu, bạn cần khai báo thông tin cá nhân để Git biết ai là người thực hiện các thay đổi (commit).

```bash
# Thiết lập tên người dùng
git config --global user.name "Nam"

# Thiết lập email
git config --global user.email "email_cua_ban@example.com"

# Kiểm tra lại cấu hình
git config --list
```

---

## 2. Khởi tạo và Liên kết Repository

### Tình huống A: Bắt đầu một dự án hoàn toàn mới ở Local
Giả sử bạn đang code dự án ECG hoặc module Verilog trên máy và muốn đưa nó lên GitHub/GitLab.

```bash
# 1. Di chuyển vào thư mục dự án của bạn
cd path/to/your/project

# 2. Khởi tạo Git repository tại local
git init

# 3. Liên kết thư mục local với Remote Repository (trên GitHub/GitLab)
git remote add origin [https://github.com/username/ten-repo-cua-ban.git](https://github.com/username/ten-repo-cua-ban.git)

# (Tùy chọn) Kiểm tra xem đã liên kết đúng chưa
git remote -v
```

### Tình huống B: Clone (Tải) một project đã có sẵn trên mạng về máy
Nếu repository đã có sẵn trên GitHub và bạn chỉ muốn tải về để làm việc tiếp.

```bash
git clone [https://github.com/username/ten-repo-cua-ban.git](https://github.com/username/ten-repo-cua-ban.git)
cd ten-repo-cua-ban
```

---

## 3. Quy trình làm việc hàng ngày (Add -> Commit -> Push)

Đây là vòng lặp bạn sẽ sử dụng nhiều nhất mỗi khi viết xong một tính năng hoặc sửa xong bug.

```bash
# 1. Kiểm tra trạng thái các file (file nào bị sửa, file nào mới tạo)
git status

# 2. Thêm các thay đổi vào Staging Area
git add .                  # Thêm TẤT CẢ các file bị thay đổi
# HOẶC
git add ten_file.v         # Chỉ thêm 1 file cụ thể (vd: ten_file.v, main.py)

# 3. Ghi lại lịch sử thay đổi (Commit)
git commit -m "Thêm tính năng tiền xử lý tín hiệu"

# 4. Đẩy code lên Remote Repository
# Nếu là lần push đầu tiên của nhánh main:
git push -u origin main
# Từ các lần sau, bạn chỉ cần gõ:
git push
```

---

## 4. Cập nhật code mới nhất từ Remote (Pull)

Khi làm việc nhóm hoặc khi bạn code trên một máy tính khác (ví dụ: clone code từ công ty về máy trạm Blackwell ở nhà), bạn cần lấy code mới nhất về trước khi bắt đầu code tiếp.

```bash
# Lấy code mới nhất từ nhánh main trên remote về và gộp vào máy bạn
git pull origin main
```
*Lưu ý: Luôn nhớ `git pull` trước khi bắt đầu công việc trong ngày để tránh xung đột code (conflict).*

---

## 5. Quản lý nhánh (Branching)

Làm việc trên nhánh (branch) giúp bạn thử nghiệm các mô hình AI hay thuật toán mới một cách an toàn mà không làm hỏng source code chính.

```bash
# Xem danh sách các nhánh hiện có
git branch

# Tạo một nhánh mới và chuyển sang nhánh đó ngay lập tức
git checkout -b ten-nhanh-moi
# Ví dụ: git checkout -b test-viterbi-decoder

# Chuyển đổi qua lại giữa các nhánh đã có
git checkout main

# Gộp code từ nhánh khác vào nhánh hiện tại (Ví dụ đang ở 'main', muốn gộp 'ten-nhanh-moi' vào)
git merge ten-nhanh-moi
```

---

## 6. Các lệnh hữu ích khác để xử lý sự cố

* **Xem lịch sử commit:**
    ```bash
    git log
    git log --oneline  # Xem lịch sử rút gọn
    ```

* **Hủy bỏ thay đổi chưa commit (Khôi phục file về trạng thái cũ):**
    ```bash
    git checkout -- ten_file.py
    ```

* **Xóa file khỏi Staging Area (lỡ `git add` nhầm):**
    ```bash
    git reset HEAD ten_file.py
    ```
```

Bạn có thể copy đoạn text từ khối mã phía trên, tạo một file tên là `README.md` trong thư mục gốc của project và dán vào nhé! Có cần bổ sung thêm các phần nâng cao như xử lý conflict (xung đột code) không?