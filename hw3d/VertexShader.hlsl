struct VSOut
{
	float4 color : COLOR;
	float4 pos : SV_POSITION;
};

cbuffer CBuf
{
	// The keyword matrix indicates 4x4 float
	// row_major is slower than using a transposed matrix
	// The inverse of a rotation matrix is its transpose
	matrix transform;
};

VSOut main(float4 pos : POSITION, float4 color : COLOR)
{
	VSOut vso;
	vso.pos = mul(float4(pos.x, pos.y, 0.0f, 1.0f), transform);
	vso.color = color;
	return vso;
}