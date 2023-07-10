# if (x > 100 && x < 1000) {
#         printf("medium\n");
#     } else {
#         printf("small/big\n");
# }

# !(x > 100 && x < 1000)

# x <= 100 || x >= 1000

	# x in $t0
	ble	$t0, 100, small_big
	bge	$t0, 1000, small_big
medium:
	# printf("medium\n");
	j	end
small_big:
	# printf("small/big\n");
end:

# x > 100 && x < 1000

	bgt	$t0, 100, true
	j	false

true:
	blt	$t0, 1000, false

	j	end
false:

end:
