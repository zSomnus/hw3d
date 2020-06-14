cbuffer CBuf
{
	// The keyword matrix indicates 4x4 float
	// row_major is slower than using a transposed matrix
	// The inverse of a rotation matrix is its transpose
	matrix transform;
};

float4 main(float4 pos : POSITION) : SV_POSITION
{
	return mul(pos, transform);
}