#pragma once
#include"monoTest.h"
#include"GLDebug.h"
//#define KEY_DOWN(x) ((GetAsyncKeyState(x)&0x8000)?1:0)

//static ShaderProgramSrc ParseShaderPath(const std::string& path)
//{
//	std::ifstream fs(path);
//	std::string l;
//	std::stringstream s[2];
//
//	enum class shaderType
//	{
//		None = -1,
//		Vertex = 0,
//		Fragment = 1
//	};
//
//	shaderType shaderty = shaderType::None;
//
//	while (getline(fs, l))
//	{
//		if (l.find("#Shader") != std::string::npos)
//		{
//			if (l.find("vertex") != std::string::npos)
//			{
//				shaderty = shaderType::Vertex;
//			}
//			else if (l.find("fragment") != std::string::npos)
//			{
//				shaderty = shaderType::Fragment;
//			}
//		}
//		else
//		{
//			s[(int)shaderty] << l << "\n";
//		}
//	}
//
//	return { s[0].str(),s[1].str() };
//}
//
//static int CompileShader(const std::string& src, unsigned int type)
//{
//	unsigned int id = glCreateShader(type);
//	const char* s = src.c_str();
//	glShaderSource(id, 1, &s, nullptr);
//	glCompileShader(id);
//
//	int r;
//	glGetShaderiv(id, GL_COMPILE_STATUS, &r);
//	if (r == GL_FALSE)
//	{
//		printf("Shader Compile Error");
//		int l = 0;
//		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &l);
//		char* message = (char*)malloc(l * sizeof(char));
//		glGetShaderInfoLog(id, l, &l, message);
//		std::cout << message << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
//	}
//
//	return id;
//}
//
//static int CreateShader(const std::string vertex, const std::string fragment)
//{
//	unsigned int program = glCreateProgram();
//	// unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
//	// unsigned int fr = glCreateShader(GL_FRAGMENT_SHADER);
//
//	unsigned int vs = CompileShader(vertex, GL_VERTEX_SHADER);
//	unsigned int fr = CompileShader(fragment, GL_FRAGMENT_SHADER);
//
//	glAttachShader(program, vs);
//	glAttachShader(program, fr);
//	glLinkProgram(program);
//	glValidateProgram(program);
//
//	glDeleteShader(vs);
//	glDeleteShader(fr);
//
//	return program;
//
//}


int main(void)
{

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}


	{
	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		printf("ERROR");

	// std::cout << glGetString(GL_VERSION) << std::endl;
	{
		float d[16] =
		{
		0, 0,0,0,
		0,540,0.0,1.0,
		960,0,1.0f,0.0f,

		960,540,1.0f,1.0f
		};

		unsigned int inde[] = {
		0,1,2,
		1,2,3
		};


		glm::mat4 proj = glm::ortho(0.0f, 1920.0f, 0.0f, 1080.0f, -1.0f, 1.0f);
		glm::vec3 CameraTranslate(-100, 100, 0);
		glm::vec3 ModTransform(0, 0, 0);
		glm::mat4 trom_MV;// = glm::translate(glm::mat4(1.0f), CameraTranslate);
		//glm::mat4 modTr= glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
		//glm::mat4 mvp = modTr*proj * trom;

		unsigned int buf;
		//	unsigned int vao;
#pragma region MyRegion1
		//glDebugCall(glGenVertexArrays(1, &vao));
///glDebugCall(glBindVertexArray(vao));
/*
glGenBuffers(1, &buf);
glBindBuffer(GL_ARRAY_BUFFER, buf);
glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), d, GL_STATIC_DRAW);
glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
unsigned int ibo;
glGenBuffers(1, &ibo);
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), inde, GL_STATIC_DRAW);
*/
//abstract mode
/*VertexBuffer VB(d, 8 * sizeof(float));
VB.Bind();
glEnableVertexAttribArray(0);
glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
IndexBuffer  IB(inde, 6);
IB.Bind();
glDebugCall(glBindVertexArray(0));*/

#pragma endregion




		VertexArrayObject va;
		VertexBuffer VB(d, 16 * sizeof(float));
		VertexBufferLayout vbl;
		vbl.Push<float>(2);
		vbl.Push<float>(2);
		IndexBuffer IB(&inde, 6);
		va.BufferLayoutEnable(VB, vbl);
		va.UnBind();

#pragma region MyRegion2
		glDebugCall(glBindVertexArray(0));

		/*

		float d2[12] =
		{
		0, -1,
		0, 1,
		1,-1,

		 1,1
		};

		unsigned int inde2[] = {
		0,1,2,
		1,2,3
		};


		unsigned int vao2;

		glDebugCall(glGenVertexArrays(1, &vao2));
		glDebugCall(glBindVertexArray(vao2));
		unsigned int buf2;
		glGenBuffers(1, &buf2);
		glBindBuffer(GL_ARRAY_BUFFER, buf2);
		glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), d2, GL_STATIC_DRAW);


		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

		unsigned int ibo2;
		glDebugCall(glGenBuffers(1, &ibo2));
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo2);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), inde2, GL_STATIC_DRAW);

		glBindVertexArray(0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		*/

#pragma endregion

		/*
		ShaderProgramSrc ssrc = ParseShaderPath("F:/OpenGL_Work/Project1/Project1/Shader.shader");

		unsigned int shader = CreateShader(ssrc.vertexPath, ssrc.fragmentPath);
		glUseProgram(shader);

		int u = glGetUniformLocation(shader, "u_Color");

		glUniform4f(u, 0.1, 0.5, 0.3, 1);

		  glBindBuffer(GL_ARRAY_BUFFER, 0);
		 */

		Shader sd("F:/OpenGL_Work/Project1/Project1/Shader.shader");
		clock_t st, ed;


		//sd.SetUniformMat4f("u_matrix_MVP",mvp);

		sd.SetUniform4f("u_Color", 1, 1, 1, 1);
		Texture tx("F:/works/kua.png");
		tx.Bind(0);
		sd.SetUniform1i("u_Tex", 0);
		/* Loop until the user closes the window */
		int i = 0;

		float it = 0;
		float l = 0.1;
		//glfwSwapInterval(1);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		Renderer rd;

		int p = 0;

		st = time(NULL);

		//GUI 

		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window, true);
		ImGui::StyleColorsDark();

		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


		Mono::MonoBehaviour* test = nullptr;
		Mono::MonoMenu* me = new Mono::MonoMenu(test);
		test = me;

		trom_MV = glm::translate(glm::mat4(1.0f), CameraTranslate);
		trom_MV = glm::translate(trom_MV, ModTransform);
		glm::mat4 mvp = proj * trom_MV;
		sd.SetUniformMat4f("u_matrix_MVP", mvp);

		me->Regist<Mono::monotest>("Update");
		while (!glfwWindowShouldClose(window))
		{
			ImGui_ImplGlfwGL3_NewFrame();

			ed = time(NULL);
			glClear(GL_COLOR_BUFFER_BIT);
			/* Render here */

			p = 0;
			float of = float(st - ed);
			//sd.SetUniform1f("u_Time", of / 10);

			va.Bind();
			rd.Draw(VB, IB, sd);
			va.UnBind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);



			if (test)
			{
				test->OnUpdate();
				test->OnRender();

				ImGui::Begin("test");
				if (test != me && ImGui::Button("<-"))
				{
					delete test;
					test = me;
				}
				test->OnGUI();
				ImGui::End();
			}
			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
			//	
			glfwSwapBuffers(window);
			/* Poll for and process events */
			glfwPollEvents();

			sd.UnBind();

		}


		ImGui_ImplGlfwGL3_Shutdown();
		ImGui::DestroyContext();
	}
		glfwTerminate();
		return 0;
	}
}
