Viết chương trình thực hiện các câu truy vấn tạo, xóa các điểm trên đồ thị, tìm đường đi ngắn nhất giữa hai điểm được cho.
(Các điểm được thể hiện là số nguyên không âm).
	- CREATE u v w
		Tạo hai điểm u và v có trọng số là w (không âm).
		Kết quả 1 nếu thành công hoặc 0 là ngược lại.
	- DELETE u v
		Xóa cạnh uv. 
		Kết quả trả về 1 nếu thành công xóa được cạnh( trường hợp có cạnh nói hai điểm) hoặc ngược lại 0.
	- SP u v
		Tìm đường đi ngắn nhất giữa hai điểm u và v
